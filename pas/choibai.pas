const
        fi='choibai.inp';
        fo='choibai.out';
var
        a:array [1..101] of longint;
        n,i,x,y,d1,d2,kq1,kq2:longint;
        f,g:text;
procedure nhap;
begin
        assign(f,fi);
        assign(g,fo);
        reset(f);
        rewrite(g);
        y:=0;kq1:=1;kq2:=1;
        d1:=1;
        readln(f,n);
        readln(f,x);
        if x<>1 then begin
                d2:=x-y;
                kq2:=d2;
        end;
        for i:=1 to (n div 2)-1 do
        begin
                if y+1<>x then
                begin
                        d2:=x-y-1;
                        if d2>kq2 then kq2:=d2;
                        if d1>kq1 then kq1:=d1;
                        d1:=1;
                end;
                y:=x;
                readln(f,x);
                if y+1=x then inc(d1);
                if i=(n div 2)-1 then
                begin
                        if d1>kq1 then kq1:=d1;
                        if n-x>kq2 then kq2:=n-x;
                end;
        end;
        if kq1>kq2 then write(g,'Nam');
        if kq1<kq2 then write(g,'Minh');
        if (kq1=kq2) and (x=n) then write(g,'Nam');
        if (kq1=kq2) and (x<>n) then write(g,'Minh');
        close(f);
        close(g);
end;
begin
        nhap;
end.