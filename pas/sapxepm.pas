const
        fi='sapxepm.inp';
        fo='sapxepm.out';
var i,j,m,n:longint;
        a:array [1..100,1..100] of longint;
        b:array [1..100000] of longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,m,n);
        for i:=1 to m do
           for j:=1 to n do
                read (f,a[i,j]);
        close(f);
end;
procedure sx;
var dem,tam:longint;
begin   dem:=0;
        for i:=1 to m do
                for j:=1 to n do
                begin
                        inc(dem);
                        b[dem]:=a[i,j];
                end;
        for i:=1 to dem do
                for j:=dem downto i do
                        if b[i]>b[j] then
                        begin
                                tam:=b[i];
                                b[i]:=b[j];
                                b[j]:=tam;
                        end;
        for i:=1 to m do
                for j:=1 to n do
                begin
                        a[i,j]:=b[dem];
                        dec(dem);
                end;
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to m do
        begin
                for j:=1 to n do
                        write(f,a[i,j]:8);
                writeln(f);
        end;
        close(f);
end;
begin
        nhap;
        sx;
        xuat;
end.
