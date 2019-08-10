const
        fi='datbom.inp';
        fo='datbom.out';
var
        a:array [1..151,1..151] of longint;
        i,j,n,d:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
                for j:=1 to n do
                read(f,a[i,j]);
        close(f);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        d:=0;
        for i:=1 to n do
                for j:=1 to n do
                        if (a[i,j]=1) or ((a[i,j+1]=1) and (a[i+1,j+1]=1)) then
                        begin
                                a[i,i]:=0;a[i+1,j]:=0;a[i,j+1]:=0;a[i+1,j+1]:=0;
                                writeln(f,i,' ',j);inc(d);
                        end;
        write(f,d,' qua bom');
        close(f);
end;
begin
        nhap;
        xuly;
end.