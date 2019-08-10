const
        fi='modulo.inp';
        fo='modulo.out';
var
        s:ansistring;
        n,i,kq,k:longint;
        f,g:text;
procedure xuat;
begin
        kq:=(ord(s[1])-48) mod k;
        delete(s,1,1);
        while s<>'' do
        begin
                kq:=(kq*10+ord(s[1])-48) mod k;
                delete(s,1,1);
        end;
        writeln(g,kq);
end;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        assign(g,fo);
        rewrite(g);
        readln(f,n,k);
        for i:=1 to n do
        begin
                readln(f,s);
                xuat;
        end;
        close(f);
        close(g);
end;
begin
        nhap;
end.
