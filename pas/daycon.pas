const
        fi='daycon.inp';
        fo='daycon.out';
var
        a:array [1..100000] of longint;
        n,j,i,d,c,t,kq,h,dem:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
                read(f,a[i]);
        close(f);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        d:=1;c:=1;kq:=a[1];t:=0;dem:=0;
        for i:=1 to n do
        begin
                if a[i]<=a[i+1] then
                begin
                        t:=t+a[i];
                        inc(dem);
                end
                else
                begin
                        if t>kq then
                        begin
                                d:=i-dem+1;
                                c:=i;
                                kq:=t;
                        end;
                        t:=0;
                        dem:=0;
                end;
        end;
                write(f,d,' ',c);
        close(f);
end;
begin
        nhap;
        xuat;
end.
