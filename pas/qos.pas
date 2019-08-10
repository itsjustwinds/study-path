const
        oo=255;
var
        f:array[1..1000,1..1000] of byte;
        q:array[1..1000000] of integer;
        tong:array[1..1000000] of longint;
        dd:array[1..1000000,1..1000] of boolean;
        res:array[1..1000] of longint;
        trace:array[1..1000000] of longint;
        i,j,n,m,t,k,Tmin,Cmin,dem,dem1,l,r:longint;
        kt:boolean;
procedure dijkstra;
var     d:array[1..1000] of longint;
        fr:array[1..1000] of boolean;
        minx,i,j,v,u:longint;
begin
        for i:=1 to n do
                d[i]:=f[1,i];
        for i:=1 to n do
                fr[i]:=true;
        fr[1]:=false;
        repeat
                u:=0;minx:=oo;
                for i:=1 to n do
                if (d[i]<minx) and (fr[i]) then
                begin
                        u:=i;
                        minx:=d[i];
                end;
                if u<>0 then fr[u]:=false;
                if (u=0) or (u=t) then break;
                for v:=1 to n do
                        if (fr[v]) and (d[v]>d[u]+f[u,v]) then
                        d[v]:=d[u]+f[u,v];
        until false;
        Tmin:=d[t];
end;
procedure nhap;
var     x,y:longint;
        v:byte;
begin
        readln(n,m,t,k);
        for i:=1 to n do
                for j:=1 to n do
                        f[i,j]:=oo;
        cmin:=oo;
        for i:=1 to m do
        begin
                readln(x,y,v);
                f[x,y]:=v;
                if v<Cmin then Cmin:=v;
        end;
        kt:=false;
        dem:=0;
        dem1:=-1;
        dijkstra;
end;
procedure check(r:longint);
begin
        inc(dem);
        if dem=k then
        begin
                dem1:=0;
                while r<>1 do
                begin
                        inc(dem1);
                        res[dem1]:=q[r];
                        r:=trace[r];
                end;
                inc(dem1);
                res[dem1]:=1;
                kt:=true;
        end;
end;
procedure bfs;
var     u,v,tmp:longint;
begin
        if (t=1) and (k=1)then
        begin
                writeln(1);
                writeln(t);
        end
        else
        begin
                for i:=1 to n do
                        dd[1,i]:=true;
                dd[1,1]:=false;
                l:=1;r:=1;
                q[1]:=1;
                tong[1]:=0;
                repeat
                        if kt then exit;
                        u:=q[l];
                        tmp:=tong[l];
                        inc(l);
                        for v:=2 to n do
                        if (f[u,v]<oo) and (dd[l-1,v]) and (tmp+f[u,v]<=Cmin+Tmin) then
                        begin
                                inc(r);
                                q[r]:=v;
                                tong[r]:=tmp+f[u,v];
                                trace[r]:=l-1;
                                for i:=1 to n do
                                        dd[r,i]:=dd[l-1,i];
                                dd[r,v]:=false;
                                if v=t then check(r);
                                if kt then exit;
                        end;
                until l>r;
        end;
end;
procedure xuat;
begin
        if dem1=-1 then writeln(dem1)
        else begin
        writeln(dem1);
        for i:=dem1 downto 1 do
                write(res[i],' ');
        end;
end;
begin
        {assign(input,'qos.inp');
        assign(output,'qos.out');
        reset(input);
        rewrite(output); }
        nhap;
        bfs;
        xuat;
        {close(input);
        close(output);}
end.
