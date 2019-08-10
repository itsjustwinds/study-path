const
        fi='dautf.inp';
        fo='daytf.out';
var
        a:array [1..10000] of string;
        i,j,n,t,f,k,h,dem:longint;
        g:text;
procedure nhap;
begin
        assign(g,fi);
        reset(g);
        readln(g,n);
        for i:=1 to n do
                readln(g,a[i]);
        close(g);
end;
procedure xuat;
begin
        assign(g,fo);
        rewrite(g);
        dem:=0;k:=0;
        for i:=1 to n-1 do
                for j:=n downto i+1 do
                begin
                        t:=0;
                        f:=0;
                        for h:=i to j do
                        begin
                                if a[h]='T' then inc(t);
                                if a[h]='F' then inc(f);
                        end;
                        if t=f then
                                if j-i+1>dem then
                                begin
                                        dem:=j-i+1;
                                        k:=i;
                                end;
                end;
        write(g,dem,' ',k);
        close(g);
end;
begin
        nhap;
        xuat;
end.
