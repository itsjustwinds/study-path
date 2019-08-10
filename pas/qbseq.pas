uses math;
const
        oo=1000000;
var
        a:array[1..1000] of longint;
        f:array[0..1000,0..50] of longint;
        i,n,k,h:longint;
        res:int64;
procedure nhap;
begin
        readln(n,k);
        for i:=1 to n do
        read(a[i]);
end;
procedure xuly;
begin
        for i:=0 to n do
                for h:=0 to k-1 do
                        f[i,h]:=-oo;
        f[0,0]:=0;
        for i:=1 to n do
                        for h:=0 to k-1 do
                                f[i,h]:=max(f[i-1,h],f[i-1,(h+k-a[i] mod k) mod k]+1);
        writeln(f[n,0]);
end;
begin
        assign(input,'qbseq.inp');
        assign(output,'qbseq.out');
        reset(input);
        rewrite(output);
        nhap;
        xuly;
        close(input);
        close(output);
end.