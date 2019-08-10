const
        fi='smax.inp';
        fo='smax.out';
var
        a:array[1..100000] of longint;
        n,i,t,max:longint;
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
        t:=0;
        for i:=1 to n do
        begin
               t:=t+a[i];
               if t>max then max:=t;
               if t<0 then t:=0;

        end;
        write(f,max);
        close(f);
end;
begin
        nhap;
        xuat;
end.
