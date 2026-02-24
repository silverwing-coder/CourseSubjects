'''
Last update: Jan. 2025 by Sangmork Park
This psudo code is to provide a templete for lab assignments.
(No fully implemented encryption/decryption codes will be posted.)   
'''

def encrypt_function(enc_key, file_name):
    pass
    ## // FIX ME : implement the encryption function
    # 1. Read the plaintext file
    # 2. Encrypt the content using the provided key
    # 3. Write the encrypted content to a new file ("encrypted.txt")

def decrypt_function(enc_key, file_name):
    pass
    ## // FIX ME : implement the decryption function
    # 1. Read the encrypted file
    # 2. Decrypt the content using the provided key
    # 3. Write the decrypted content to a new file ("decrypted.txt")

def main():
    while True:
        option = input("Enter 'e' to encrypt, 'd' to decrypt, or 'q' to quit: ").lower()
        if option == 'e':
            enc_key = input("Enter Encryption Key: ")
            file_name = input("Enter the file name to encrypt: ")
            encrypt_function(enc_key, file_name)
        elif option == 'd':
            enc_key = input("Enter Decryption Key: ")
            file_name = input("Enter the file name to decrypt: ")
            decrypt_function(enc_key, file_name)
        elif option == 'q':
            break
        else:
            print("Invalid option. Please try again.")

if __name__ == "__main__":
    main()