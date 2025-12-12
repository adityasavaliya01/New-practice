
# define menu
menu={'Pizza':100,
      'Pasta':120,
      'Burger':70,
      'Fries':60,
      'Coffee':50}

# greetings
print("Welcome! Here's The Menu:")

# display the menu
for item, price in menu.items():
    print(f'{item}: Rs{price}')

# take order
total_amount=0
order=input('\nPlease give your order: ')

# check if the order is available or not
if order in menu:
    qnt=int(input('Enter Quantity: '))
    print('Your order is placed successfully.')
    total_amount+=menu[order]*qnt
    print(f'Your total bill is: {total_amount}')

else:
    print('Sorry this item is currently unavailable.')

while True:
    next_order=input('Do you want to give another order (Yes/No): ')
    if next_order=='Yes':
        another_order=input('Please give your order: ')
        if another_order in menu:
            qnt=int(input('Enter Quantity: '))
            print('You order is placed successfully.')
            total_amount+=menu[another_order]*qnt
            print(f'Your total bill is: {total_amount}')
        else:
            print('Sorry this item is currently unavailable.')
    else:
        print(f'\nYour final bill is: {total_amount}\nThank you for visiting. Please come again!')
        break