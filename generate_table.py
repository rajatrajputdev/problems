import os
import subprocess
from datetime import datetime

problems_dir = "leetcode-problems"  # root folder containing categories

# Collect files by category
categories = {}

for root, dirs, files in os.walk(problems_dir):
    if files:
        # Category name = last folder name in path
        category = os.path.basename(root)
        if category not in categories:
            categories[category] = []
        for file in sorted(files):
            path = os.path.join(root, file)
            rel_path = path.replace("\\", "/")

            # Problem name from filename
            problem_name = file.replace("-", " ").replace(".cpp", "")

            # Get last commit date
            try:
                result = subprocess.run(
                    ["git", "log", "-1", "--format=%ad", "--date=short", "--", path],
                    capture_output=True, text=True, check=True
                )
                last_date = result.stdout.strip()  # YYYY-MM-DD
            except subprocess.CalledProcessError:
                last_date = "N/A"

            categories[category].append((problem_name, rel_path, last_date))

# Read README
with open("README.md", "r") as f:
    content = f.read()

start_tag = "<!-- AUTO_TABLE_START -->"
end_tag = "<!-- AUTO_TABLE_END -->"
start = content.find(start_tag) + len(start_tag)
end = content.find(end_tag)

table_text = ""
for cat, files in categories.items():
    table_text += f"\n### {cat.capitalize()}\n\n"
    table_text += "| Problem | File | Date |\n"
    table_text += "| --- | --- | --- |\n"
    for name, path, date in files:
        table_text += f"| {name} | [{os.path.basename(path)}]({path}) | {date} |\n"
    table_text += "\n"

# Replace old table
new_content = content[:start] + "\n" + table_text + "\n" + content[end:]

with open("README.md", "w") as f:
    f.write(new_content)
