
const
        fi='doancon.inp';
        fo='doancon.out';
var
        a:array [1..10000] of longint;
        i,dem,n,x,y,max:longint;
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
        max:=0;
        dem:=1;
        for i:=2 to n do
        begin
                if a[i-1]<=a[i] then inc(dem)
                else
                begin
                        if dem>max then
                        begin
                                max:=dem;
                                x:=i-max;
                                y:=i-1;
                        end;
                        dem:=1;
                end;
                if i=n then
                begin
                        if dem>max then
                        begin
                                max:=dem;
                                x:=i-max;
                                y:=i-1;
                        end;
                        dem:=1;
                end;
        end;
        writeln(f,max);
        for i:=x to y do
                write(f,a[i],' ');
        close(f);
end;
begin
        nhap;
        xuat;
end.