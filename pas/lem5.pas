uses math;
var
        f:array[1..100000,1..100] of longint;
        a:array[0..100000] of longint;
        n,i,j,res,k:longint;
procedure nhap;
begin
        readln(n);
        for i:=1 to n do
                read(a[i]);
        for i:=1 to n do for j:=1 to 100 do f[i,j]:=1;
        for i:=1 to n do
                for j:=1 to 100 do
                begin
                        for k:=i-1 downto 1 do
                                if a[k]=a[i]-j then
                                begin
                                        f[i,j]:=f[k,j]+1;
                                        break;
                                end;
                        if f[i,j]>res  then res:=f[i,j];
                end;
        writeln(res);
end;
begin
        {assign(input,'lem5.inp');
        assign(output,'lem5.out');
        reset(input);
        rewrite(output);}
        nhap;
        {close(input);
        close(output);}
end.