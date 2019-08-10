const
        fi='tongm.inp';
        fo='tongm.out';
var
        a:array [1..100000] of longint;
        i,j,n,m,t,d,c,ln:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(F);
        readln(f,n,m);
        for i:=1 to n do
                read(f,a[i]);
        close(f);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        d:=1;c:=m;ln:=0;
        for i:=1 to m do
                ln:=ln+a[i];
        for i:=2 to n-m+1 do
        begin
                t:=0;
                for j:=i to i+m-1 do
                t:=t+a[j];
                if t>ln then
                begin
                        d:=i;
                        c:=i+m-1;
                        ln:=t;
                end;
        end;
        for i:=d to c do
                write(f,a[i],' ');
        close(f);
end;
begin
        nhap;
        xuat;
end.
