type
        hd=record
                x:longint;
                //th:set of 1..255;
                dem:longint;
        end;
        kq=record
                x,y:longint;
        end;
var
        n,m,i,j,count,l,r:longint;
        f:array[1..1000,1..1000] of boolean;
        res:array[1..3,1..1000] of kq;
        trace:array[1..1000000] of longint;
        q:array[1..1000000] of hd;
        dd:array[1..1000000,1..1000] of boolean;
procedure nhap;
var     x,y:longint;
begin
        readln(n,m);
        for i:=1 to n do
                for j:=1 to n do
                        f[i,j]:=false;
        for i:=1 to n do
        begin
                readln(x,y);
                f[x,y]:=true;
                f[y,x]:=true;
        end;
        count:=0;
end;
procedure result(count,u:longint);
var     v,i:longint;
begin
        for i:=1 to n-1 do
        begin
                v:=trace[u];
                res[count,i].y:=q[u].x;
                res[count,i].x:=q[v].x;
                u:=v;
        end;
end;
procedure bfs;
var
        u,v:hd;
        k:longint;
begin
        for k:=1 to n do
        begin
                l:=1;r:=1;
                q[1].x:=k;
                //q[1].th:=[k];
                for i:=1 to n do
                        dd[1,i]:=false;
                dd[1,k]:=true;
                q[1].dem:=1;
                repeat
                        u:=q[l];
                        inc(l);
                        for i:=1 to n do
                                if (dd[l-1,i]=false)and (f[u.x,i]) then
                                begin
                                        inc(r);
                                        q[r].x:=i;
                                        q[r].dem:=q[l-1].dem+1;
                                        dd[r]:=dd[l-1];
                                        dd[r,i]:=true;
                                        {q[r].x:=i;
                                        //q[r].th:=u.th+[i];
                                        q[r].dem:=u.dem+1;}
                                        trace[r]:=l-1;
                                        if u.dem+1=n then
                                        begin
                                                inc(count);
                                                result(count,r);
                                        end;
                                        if count=3 then exit;
                                end;
                                if count=3 then exit;
                until l>r;
        end;
end;
procedure xuly;
begin
        bfs;
        writeln(count);
        for i:=1 to count do
                for j:=n-1 downto 1 do
                        writeln(res[i,j].x,' ',res[i,j].y);
end;
begin
        assign(input,'vmst.inp');
        assign(output,'vmst.out');
        reset(input);
        rewrite(output);
        nhap;
        xuly;
        close(input);
        close(output);
end.
