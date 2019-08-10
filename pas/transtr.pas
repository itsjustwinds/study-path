const
        fi='stranstr.inp';
        fo='stranstr.out';
var
        s,s1:ansistring;
        d:int64;
        i:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,s1);
        read(f,s);
        close(f);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        d:=0;
        for i:=1 to length(s1) do
        begin
                d:=(d*10+ord(s1[i])-48);
                d:=d mod length(s);
        end;
        for i:=d+1 to length(s) do
                write(f,s[i]);
                for i:=1 to d do
                write(f,s[i]);
        close(f);
end;
begin
        nhap;
        xuat;
end.
