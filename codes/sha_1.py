import hashlib

def sha1_hash(input_string):
    sha1 = hashlib.sha1()
    sha1.update(input_string.encode('utf-8'))
    # Get the hexadecimal representation of the digest
    return sha1.hexdigest()

def main():
    input_string = input("Enter a string: ")
    hash_result = sha1_hash(input_string)
    print("SHA-1 Hash:", hash_result)

if __name__ == "__main__":
    main()
