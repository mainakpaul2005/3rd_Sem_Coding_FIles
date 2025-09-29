
choice = input("Create new source file? (y/n): ").lower()

if choice == 'y':
    original_file = input("New file name: ")
    print("Enter content (type EOF on a new line to finish):")
    
    lines = []
    while True:
        line = input()
        if line.strip().upper() == 'EOF':
            break
        lines.append(line)
    
    content_to_write = "\n".join(lines)
    
    with open(original_file, 'w') as f:
        f.write(content_to_write)
    print(f"File saved: {original_file}")
else:
    original_file = input("Existing source file name: ")

print(f"Reading file: {original_file}")
with open(original_file, 'r') as f:
    file_content = f.read()

copy_file = input("Destination file name: ")
with open(copy_file, 'w') as f:
    f.write(file_content)
print(f"Content copied to: {copy_file}")

print("Operation complete.")