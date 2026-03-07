import sys

with open('inc/funcoes.php', 'r', encoding='utf-8') as f:
    content = f.read()

count = 0
for i, line in enumerate(content.split('\n')):
    # very rough check, ignoring strings
    line_clean = line.split('//')[0]
    count += line_clean.count('{')
    count -= line_clean.count('}')
    print(f"Line {i+1} : Open braces = {count}")
    if count < 0:
        print(f"Extra closing brace at line {i+1}!")
        break

print(f"Final open braces: {count}")
