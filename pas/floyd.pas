const
        oo=100000000;
var
        f:array[1..100,1..100] of longint;
        trace,d:array[1..100] of longint;
        i,j,n,m,k,w,s,p:longint;
procedure result(w:longint);
var     i,j,count:longint;
        res:array[1..100] of longint;
        kq:int64;
begin
        kq:=0;
        if w=0 then
        begin
                writeln(d[p]);
        end
        else
        begin
                count:=0;
                while p<>s do
                begin
                        inc(count);
                        res[count]:=p;
                        p:=trace[p];
                end;
                inc(count);
                res[count]:=s;
                write(count,' ');
                for i:=count downto 1 do
                        write(res[i],' ');
                writeln;
        end;
end;
procedure dijk(w,s,p:longint);
var
        u,v,i,min:longint;
        dd:array[1..100] of boolean;
begin
        fillchar(dd,n,true);
        for i:=1 to n do
                if i=s then d[i]:=0
                else d[i]:=oo;
        repeat
                u:=0;min:=oo;
                for i:=1 to n do
                        if (dd[i]) and (d[i]<min) then
                        begin
                                min:=d[i];
                                u:=i;
                        end;
                dd[u]:=false;
                if (u=0) or (u=p) then break;
                for v:=1 to n do
                        if (dd[v])and (d[v]>d[u]+f[u,v]) then
                        begin
                                d[v]:=d[u]+f[u,v];
                                trace[v]:=u;
                        end;
        until false;
        if dd[p]=true then writeln(-1)
        else result(w);
end;

procedure nhap;
var     x,y:longint;
begin
        readln(n,m,k);
        for i:=1 to n do
                for j:=1 to n do
                        f[i,j]:=oo;
        for i:=1 to m do
        begin
                readln(x,y,f[x,y]);
                f[y,x]:=f[x,y];
        end;
        for i:=1 to k do
        begin
                readln(w,s,p);
                dijk(w,s,p);
        end;
end;
begin
        assign(input,'floyd.inp');
        assign(output,'floyd.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.