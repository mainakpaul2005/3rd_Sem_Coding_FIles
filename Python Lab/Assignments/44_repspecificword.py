#WAP to replace a specific word in a string with another word.

def replace_word(original_string, old_word, new_word):
    modified_string = original_string.replace(old_word, new_word)
    return modified_string

s1 = input("Enter a string: ")
s2 = input("Enter the word to be replaced: ")
s3 = input("Enter the new word: ")

result = replace_word(s1, s2, s3)
print("Modified string:", result)
