const
        fi='ocsen.inp';
        fo='ocsen.out';
var
        a,b,v:longint;
        kq:longint;
        m,m1,t1,t2:real;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,a,b,v);
        close(f);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        t1:=v div a;
        if v mod a<>0 then t1:=t1+1;
        t2:=v div b;
        if v mod b<>0 then t2:=t2+1;
        m:=t2/t1;
        m1:=v/m;
        if (v/m)-trunc(v/m)<>0 then kq:=trunc(v/m)+1
        else kq:=trunc(v/m);
        write(f,kq);
        close(f);
end;
begin
        nhap;
        xuly;
end.