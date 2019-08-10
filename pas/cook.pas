uses math;
type
        td=record
                x,y:longint;
        end;
var
        a,kq:array[1..10] of td;
        dd:array[1..10] of boolean;
        i,j,n:longint;
        res:longint;
procedure check(n:longint);
var     i,s,p:longint;
begin
        s:=1;p:=0;
        for i:=1 to n do
        begin
                s:=s*kq[i].x;
                p:=p+kq[i].y;
        end;
        res:=min(res,abs(s-p));
end;
procedure try(i,t:longint);
var     j:longint;
begin
        for j:=t to n do
        if dd[j] then
        begin
                dd[j]:=false;
                kq[i].x:=a[j].x;
                kq[i].y:=a[j].y;
                check(i);
                if j<n then try(i+1,j+1);
                dd[j]:=true;
        end;
end;
procedure nhap;
var     u,v:longint;
begin
        readln(n);
        for i:=1 to n do
        begin
                readln(u,v);
                a[i].x:=u;
                a[i].y:=v;
        end;
        fillchar(dd,n,true);
        res:=maxlongint;
        try(1,1);
        writeln(res);
end;
begin
        assign(input,'cook.inp');
        assign(output,'coook.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.