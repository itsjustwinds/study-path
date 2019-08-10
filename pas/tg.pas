const
        fi='tg.inp';
        fo='tg.out';
var
        a:array [1..100,1..100] of longint;
        m,n,i,j,min,max:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,m,n);
        for i:=1 to m do
        begin
                for j:=1 to n do
                        read(f,a[i,j]);
                readln(f);
        end;
        close(f);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        min:=maxlongint;
        for i:=1 to m do
                for j:=n downto 1 do
                begin
                        if j-i>=0 then
                                if (a[i,j]<min) and (a[i,j]>=0) then min:=a[i,j];
                        if (a[m,n]<min) and (a[m,n]>=0) then min:=a[m,n];
                end;
        max:=-maxlongint;
        for i:=m downto 1 do
                for j:=1 to n do
                begin
                        if i-j>=0 then
                                if (a[i,j]>max) and (a[i,j]<0) then max:=a[i,j];
                                if (a[1,1]>max) and (a[1,1]<0) then max:=a[1,1];
                end;
        writeln(f,'tren:',min);
        write(f,'duoi:',max);
        close(f);
end;
begin
        nhap;
        xuat;
end.
