const
        fi='matkhau.inp';
        fo='matkhau.out';
var
        a:array [1..100] of longint;
        k,n,i,j:longint;kt:boolean;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,k);
        for i:=1 to k do
                read(f,a[i]);
        close(f);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to maxlongint do
        begin
                kt:=true;
                for j:=1 to k do
                        if i mod a[j]<>0 then kt:=false;
                if kt=true then
                begin
                n:=i;
                write(f,n);
                break;
                end;
         end;
         close(f);
end;
begin
                nhap;
                xuat;
end.

