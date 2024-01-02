# Test Libft

## Setup
After [installation](/docs/README.md) move to __`test/`__ directory:
```console
cd tests/
```
Compile tests:
```console
make all && make clean
```
Then run:
```console
clear && ./libfttest
```
To return everything to original state:
```console
make fclean
```

## Issues
> [!WARNING]
> Several functions have issue with working with huge numbers, that's why I added some restrictions (in this case they will return **inf**)