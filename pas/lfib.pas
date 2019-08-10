var
        a,b,kq,m:int64;
        t,i,j,k,n:longint;
procedure sub1;
var
        t:int64;
        i:longint;
begin
        a:=a mod m;
        b:=b mod m;
        kq:=(a+b) mod m;
        for i:=3 to n do
        begin
                t:=(a+b+1) mod m;
                a:=b;
                b:=t;
                kq:=(kq+b) mod m;
        end;
        writeln(kq);
end;
procedure sub2;
var     i:longint;
        t1,t2,t:int64;
begin
        kq:=(sqr(a)+sqr(b)) mod m;
        for i:=3 to n do
        begin
                t:=a+b+1;
                a:=b;
                b:=t;
                kq:=(kq+sqr(b)) mod m;
        end;
        writeln(kq);
end;
procedure nhap;
begin
        readln(t);
        for i:=1 to t do
        begin
                readln(a,b,n,k,m);
                if k=1 then sub1
                else sub2;
        end;
end;
begin
        assign(input,'lfib.inp');
        assign(output,'lfib.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.
