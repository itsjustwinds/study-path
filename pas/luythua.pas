const
        fi='luythua.inp';
        fo='luythua.out';
var
        n,i,dem,t,a,j,tu:longint;
        k:array [1..20] of longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        read(f,n);
        close(f);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        t:=1;
        for i:=2 to n do
        begin
                a:=i;
                for j:=2 to a do
                begin
                        dem:=0;
                        while a mod j=0 do
                        begin
                                a:=a div j;
                                inc(dem);
                        end;
                        k[j]:=k[j]+dem;
                end;
        end;
        for i:=2 to n do
                t:=t*(k[i]+1);
        t:=t-1;
        write(f,t);
        close(F);
end;
begin
        nhap;
        xuat;
end.
