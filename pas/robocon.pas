type
        vt=record
                x,y,d:longint;
        end;
var
        f:array[0..501,0..501] of boolean;
        q1,q2:array[1..5020020] of vt;
        d1,d2:array[1..501,1..501] of longint;
        kt:boolean;
        i,j,n,m,dht,l1,l2,r1,r2,kq:longint;
procedure nhap;
var     x,y:longint;
begin
        readln(n,m);
        for i:=1 to n do
                for j:=1 to n do
                        f[i,j]:=true;
        for i:=0 to n+1 do
        begin
                f[0,i]:=false;
                f[i,0]:=false;
                f[n+1,i]:=false;
                f[i,n+1]:=false;
        end;
        for i:=1 to m do
        begin
                readln(x,y);
                f[x,y]:=false;
        end;
end;
procedure push1(x,y,z:longint);
begin
        inc(r1);
        q1[r1].x:=x;
        q1[r1].y:=y;
        q1[r1].d:=z;
        d1[x,y]:=z;
        if d2[x,y]=z then
        begin
                kt:=true;
                kq:=z;
                exit;
        end;
end;
procedure push2(x,y,z:longint);
begin
        inc(r2);
        q2[r2].x:=x;
        q2[r2].y:=y;
        q2[r2].d:=z;
        d2[x,y]:=z;
end;
procedure bfs2(bd:longint);
var     u:vt;
        t1,t2:longint;
begin
        while l2<=r2 do
        begin
                u:=q2[l2];
                inc(l2);
                if u.d=bd+1 then
                begin
                        dec(l2);
                        exit;
                end;
                t1:=u.x;t2:=u.y;
                if f[t1,t2-1] and (d2[t1,t2-1]<>bd+1) then push2(t1,t2-1,bd+1);
                if f[t1+1,t2] and (d2[t1+1,t2]<>bd+1) then push2(t1+1,t2,bd+1);
                if f[t1+1,t2-1] and (d2[t1+1,t2-1]<>bd+1) then push2(t1+1,t2-1,bd+1);

        end;
end;
procedure bfs1;
var
        u:vt;
        t1,t2:longint;
begin
        for i:=1 to 501 do
        for j:=1 to 501 do
        begin
                d1[i,j]:=-1;
                d2[i,j]:=-1;
        end;
        kt:=false;
        r1:=0;r2:=0;l1:=1;l2:=1;
        push1(1,1,0);
        push2(1,n,0);
        dht:=0;
        while l1<=r1 do
        begin
                if kt then exit;
                u:=q1[l1];
                inc(l1);
                if u.d=dht then
                begin
                        bfs2(dht);
                        inc(dht);
                end;
                t1:= u.x ; t2:=u.y;
                if f[t1+1,t2] and (d1[t1+1,t2]<>u.d+1) then push1(t1+1,t2,u.d+1);
                if f[t1,t2+1] and (d1[t1,t2+1]<>u.d+1) then push1(t1,t2+1,u.d+1);
                if f[t1+1,t2+1] and (d1[t1+1,t2+1]<>u.d+1) then push1(t1+1,t2+1,u.d+1);

        end;
end;
begin
        assign(input,'robocon.inp');
        assign(output,'robocon.out');
        reset(input);
        rewrite(output);
        kq:=1000000000;
        nhap;
        bfs1;
        writeln(kq);
        close(input);
        close(output);
end.
