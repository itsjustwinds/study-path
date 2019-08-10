const
        fi='demso.inp';
        fo='demso.out';
var
        a:array [1..10000000] of boolean;
        x,n,d,i:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        fillchar(a,sizeof(a),false);
        readln(f,n);
        for i:=1 to n do
        begin
                read(f,x);
                a[x]:=true;
        end;
        close(f);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        d:=0;
        for i:=1 to n do
                if not (a[i]) then inc(d);
        write(f,d);
        close(f);
end;
begin
        nhap;
        xuat;
end.