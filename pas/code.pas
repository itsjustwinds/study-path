CONST
        fi='code.inp';
        fo='code.out';
var
        a:array [1..100000000] of longint;
        n,c,i:longint;
        f:text;
procedure  nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
        begin
                readln(f,c);
                inc(a[c]);
        end;
        close(f);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to maxlongint do
                if a[i]=0 then
                begin
                        write(f,i);
                        break;
                end;
        close(f);
end;
begin
        nhap;
        xuat;
end.