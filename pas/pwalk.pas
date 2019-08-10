var
        q:array[1..1000000] of longint;
        d:array[1..1000000] of longint;
        f:array[1..1000,1..1000] of longint;
        n,i,j,s,p,k:longint;
        res:int64;
procedure bfs;
var     l,r,u,v,t,i,j:longint;
        dd:array[1..1000] of boolean;
begin
        for i:=1 to n do dd[i]:=true;
        res:=0;
        l:=1;r:=1;
        if s=p then exit;
        q[1]:=s;
        d[1]:=0;
        repeat
                u:=q[l];
                inc(l);
                for i:=1 to n do
                if (dd[i]) and (f[u,i]<>0) then
                begin
                        if i=p then
                        begin
                                res:=d[l-1]+f[u,i];
                                exit;
                        end;
                        inc(r);
                        q[r]:=i;
                        d[r]:=d[l-1]+f[u,i];
                        dd[i]:=false;
                end;
        until l>r;
end;
procedure nhap;
var     u,v,l:longint;
begin
        readln(n,k);
        for i:=2 to n do
        begin
                read(u,v,f[u,v]);
                f[v,u]:=f[u,v];
        end;
        for i:=1 to k do
        begin
                readln(s,p);
                bfs;
                writeln(res);
        end;
end;
begin
        {assign(input,'pwalk.inp');
        assign(output,'pwalk.out');
        reset(input);
        rewrite(output);}
        nhap;
        {close(input);
        close(output);}
end.