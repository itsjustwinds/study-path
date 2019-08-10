var
        m,n,kq,tmp:int64;

procedure nhap;
begin
        readln(n,m);
end;
procedure xuly;
var     k,h:int64;
begin
       { if n mod m=0 then write(0)
        else
        begin }
                kq:=0;
                repeat
                        if n mod m=0 then break;
                        if n>m then n:=n mod m;
                        if m mod n=0 then
                        begin
                                kq:=kq+n*((m div n)-1);
                                break;
                        end
                        else
                        begin
                                kq:=kq+n*(m div n);
                                {h:=n*(m div n);}
                                m:=m mod (n*(m div n));
                        end;
                until false;
                write(kq);
end;
begin
        assign(input,'share.inp');
        assign(output,'share.out');
        reset(input);
        rewrite(output);
        nhap;
        xuly;
        close(input);
        close(output);
end.
