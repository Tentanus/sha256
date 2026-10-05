## GDB quick summary

### Start debugging
```bash
  $> gdb ./a.out
```

### Common commands
```
  (gdb) break main               # set breakpoint at main
  (gdb) b main
  (gdb) b my_function            # set breakpoint at a function
  (gdb) b file.cpp:42            # set breakpoint at a specific line

  (gdb) run                      # start program
  (gdb) r
  (gdb) next                     # execute next line, step over calls
  (gdb) n
  (gdb) step                     # execute next line, step into calls
  (gdb) s
  (gdb) continue                 # continue until next breakpoint
  (gdb) c
  (gdb) list                     # show source around current line
  (gdb) l
  (gdb) print variable_name      # print value of a variable
  (gdb) p variable_name
  (gdb) backtrace                # show call stack
  (gdb) bt
  (gdb) up                       # move to caller frame (higher up the stack)
  (gdb) down                     # move to callee frame (lower in the stack)
  (gdb) frame 2                  # jump to a specific frame number
  (gdb) quit                     # exit gdb
  (gdb) q
```
### Useful extras
```bash
  $> gdb -q ./a.out
  $> gdb --args ./a.out arg1 arg2
  (gdb) info break              # show all breakpoints
  (gdb) disable 1               # disable breakpoint 1
  (gdb) enable 1                # enable breakpoint 1
  (gdb) delete 1                # delete breakpoint 1
  (gdb) watch x                 # stop when a variable changes
  (gdb) finish                  # run until the current function returns
  (gdb) until                   # run until the current loop or line
  (gdb) info locals            # show local variables
```
