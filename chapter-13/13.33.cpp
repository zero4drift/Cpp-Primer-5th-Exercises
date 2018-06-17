// Both functions aim to modify the exact Folder object passed in.
// if the type of parameter of save and remove is 'Folder': that would use the argument to copy initialize the paremeter, both functions aim to modify the Folder object passed in, not the copy of it.
// if it is 'const Folder &', it is impossibile to modify a const Folder object, the expressions within function body are illegal.
