# https://savannah.gnu.org/bugs/?55469

jit_enable (true);
jit_startcnt (5);

x = 1 + 1i;
for j = 1:5
    x = x + 1;
endfor
