import pygame

def init():
    pygame.init()
    window = pygame.display.set_mode((300, 200))

# def checkKey(keyName):
def getKey(keyName):
    ans = False

    for event in pygame.event.get():
        pass

    keyInput = pygame.key.get_pressed()
    # print(keyInput)
    myKey = getattr(pygame, 'K_{}'.format(keyName))
    # print(myKey)

    if keyInput[myKey]:
        ans = True
    pygame.display.update()

    return ans

def main():
    # print(getKey('a'))
    if getKey("LEFT"):
        print("Left key pressed.")
    elif getKey("RIGHT"):
        print("Rignt key pressed.")
    elif getKey("UP"):
        print("Up key pressed.")
    elif getKey("DOWN"):
        print("Down key pressed.")
    elif getKey("w"):
        print("w key pressed.")


if __name__ == '__main__':
    init()
    while True:
        main()