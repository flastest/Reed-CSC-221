to build program: 
I wish I made a MAKEFILE, but my cygwin isn't there yet.
Instead, to compile, type:     g++ test_tree.cc tree.cc -o test_tree.exe
and, to run, type: ./test_tree.exe 

            126
           /   \
          /     \
        -5       12
        / \     /
      12   6    3
          /
         9

What this code does test the above tree. It prints the path to 9 (or whatever int search is), and then confirms that that path (LRL in this case) points to 9. Then it does some more tests on other numbers in the tree. After that, the tree is destroyed.
