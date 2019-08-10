var
        a:array[0..100,0..100] of longint;
        dd:array[1..100] of boolean;
        d,t:array[0..100] of longint;
        i,j,s,p,n,m,x,y,k:longint;
procedure nhap;
begin
        readln(n,m,s,p);
        for i:=1 to n do
                for j:=1 to n do
                        if i=j then a[i,j]:=0
                        else a[i,j]:=1000;
        for i:=1 to m do  readln(x,y,a[x,y]);
end;
procedure dijk;
var
        min,u,v,i:longint;
begin
        for i:=1 to n do
        begin
                d[i]:=a[s,i];
                t[i]:=s;
        end;
        fillchar(dd,n,true);
        repeat
                u:=0;
                min:=1000;
                for i:=1 to n do
                        if (dd[i]) and (d[i]<min) then
                        begin
                                min:=d[i];
                                u:=i;
                        end;
                if (u=0) or(u=p) then break;
                dd[u]:=false;
                for v:=1 to n do
                        if (dd[v]) and (d[v]>d[u]+a[u,v]) then
                        begin
                                d[v]:=d[u]+a[u,v];
                                t[v]:=u;
                        end;
        until false;
end;
procedure xuly;
begin
        dijk;
        if d[p]=maxlongint then write(-1)
        else while p<>s do
        begin
                write(p,' ');
                p:=t[p];
        end;
        writeln(s);
end;

begin
        assign(input,'minpath.inp');
        assign(output,'minpath.out');
        reset(input);
        rewrite(output);
        nhap;
        xuly;
        close(input);
        close(output);
end.