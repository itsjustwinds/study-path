Const

Datin = 'Data.dat';

Datout = 'Result.dat';

Bt=8;

MAX=63000;

Var

a:array[0..MAX] of byte;

f:text;

Procedure Finish;

Var i,j:longint;

Function LayBit(x,j:longint):byte;

Begin

LayBit:=(x shr j) and 1;

End;

Begin

Assign(f,DATOUT);rewrite(f);

For i:=0 to max do

For j:=0 to bt-1 do

If LayBit(a[i],j)=1 then Write(f,(i*bt+j),' ');

Close(f)

End;

Procedure Start;

Var i,tg:longint;

Procedure BatBit(x,y:longint);

Begin

A[x]:=a[x] or (1 shl y)

End;

Begin

Fillchar(a, sizeof (a), 0);

Assign(f,DATIN);reset(f);

While not seekeof(f) do

Begin

Read(f,tg);

BatBit(tg div bt,tg mod bt)

End;

Close(f)

End;

BEGIN

Start;

Finish

END.