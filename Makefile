all: converter display
	
converter: sudoku_converter.c
	@gcc -o sudoku_converter sudoku_converter.c
display: sudoku_display.c
	@gcc -o sudoku_display sudoku_display.c
