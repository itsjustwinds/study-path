const
        fi='daycon2.inp';
        fo='daycon2.out';
var
        a,b:array [1..100000] of longint;
        n,i,j,d,h,t,tong,k:longint;
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
        d:=1;
        t:=a[1];
        tong:=a[1];
        k:=0;
        for j:=2 to n do
                if a[j]-1=a[j-1] then
                begin
                        inc(d);t:=t+a[j];
                end
                else begin
                        if t>tong then
                        begin
                                tong:=t;k:=0;
                                for h:=j-d to j-1 do
                                begin
                                        inc(k);
                                        b[k]:=a[h];
                                end;
                                t:=a[j];
                                d:=1;
                        end;
                      end;
        for i:=1 to k do
                write(f,b[i],' ');
        close(f);
end;
begin
        nhap;
        xuat;
end.