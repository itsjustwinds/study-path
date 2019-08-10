type
        td=record
                x,y:integer;
        end;
var
        q:array[1..1000000] of td;
        dem:array[1..1000000] of longint;
        f:array[1..100,1..100] of char;
        a:array[1..4] of longint =(-1,0,1,0);
        b:array[1..4] of longint =(0,1,0,-1);
        i,j,n,m:longint;
        vtbd,vtkt:td;
procedure nhap;
begin
        readln(n,m);
        for i:=1 to n do
        begin
                for j:=1 to m do
                begin
                        read(f[i,j]);
                        if f[i,j]='C' then
                        begin
                                vtbd.x:=i;
                                vtbd.y:=j;
                        end;
                        if f[i,j]='B' then
                        begin
                                vtkt.x:=i;
                                vtkt.y:=j;
                        end;
                end;
                readln;
        end;
end;
procedure bfs;
var     u,v:td;
        t,i,l,r:longint;
begin
        l:=1;r:=1;q[1].x:=vtbd.x;q[1].y:=vtbd.y;
        dem[1]:=1;
        repeat
                u:=q[l];
                inc(l);
                t:=dem[l-1];
                for i:=1 to 4 do
                if (u.x+a[i]>=1) and (u.x+a[i]<=n) and (u.y+b[i]>=1) and (u.y+b[i]<=m) and ((f[u.x+a[i],u.y+b[i]]='.')or (f[u.x+a[i],u.y+b[i]]='B')) then
                begin
                        v.x:=u.x+a[i];v.y:=u.y+b[i];
                        inc(r);
                        q[r]:=v;
                        if (q[r].x=vtkt.x)and (q[r].y=vtkt.y) then
                        begin
                                writeln(t);
                                exit;
                        end;
                        dem[r]:=t+1;
                        f[v.x,v.y]:='*';
                end;
        until l>r;
end;
begin
        {assign(input,'vmunch.inp');
        assign(output,'vmunch.out');
        reset(input);
        rewrite(output);}
        nhap;
        bfs;
        {close(input);
        close(output);}
end.