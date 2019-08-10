const
        fi='chain.inp';
        fo='chain.out';
var
        a:array [1..10000] of longint;
        i,dem,n:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
                readln(f,a[i]);
        close(f);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        dem:=0;
        while a[1]=1 do
        begin
                for i:=1 to n-1 do a[i]:=a[i+1];
                dec(n);
        end;
        for i:=2 to n do
        begin
                if (a[i]<>1) and (a[i]<>2) then inc(dem);
                if (a[i]=2) and (i=n) then inc(dem);
        end;
        writeln(f,dem);
        close(f);
end;
begin
        nhap;
        xuat;
end.
