uses math;
var
        a:array[1..100] of longint;
        i,j,maxn,n:longint;
        res:int64;
procedure nhap;
begin
        readln(n);
        for i:=1 to n do
        begin
                read(a[i]);
                maxn:=max(maxn,a[i]);
        end;
        for i:=1 to n do
                res:=res+maxn-a[i];
        writeln(res);
end;
begin
        {assign(input,'392a.inp');
        assign(output,'392a.out');
        reset(input);
        rewrite(output);}
        nhap;
        {close(input);
        close(output);}
end.