const
        fi='ps.inp';
        fo='ps.out';
var
        a:array [1..1000000] of longint;
        t:int;
        f:text;
        i,j,l,h,n:longint;
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
        l:=0;h:=0;
        for i:=1 to n do
        begin
                t:=a[i];
                for j:=i+1 to n do
                begin
                        t:=t+a[j];
                        if t>0 then
                                if (j-i)>(h-l) then
                                begin
                                        h:=j;
                                        l:=i;
                                end;
                end;
        end;
        write(f,l,' ',h);
        close(f);
end;
begin
        nhap;
        xuat;
end.