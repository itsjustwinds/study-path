type
        arr=array[1..3,1..10] of longint;
var
        a:array[1..3,1..10] of longint;
        tx,ty:array[1..4] of longint;
        tracex,tracey,tracestt:array [1..70000000] of longint;
        dd:array[0..1000000000] of boolean;
        gt:array[1..11] of longint;
        n,i,j,kqx,kqy,vtbd:longint;
procedure result(vt,vtx,vty:longint);
var     d,t1,t2:longint;
        kqx,kqy:array[0..1000] of longint;
begin
        d:=0;
        while (vt<>vtbd) do
        begin
                inc(d);
                kqx[d]:=vtx;
                kqy[d]:=vty;
                t1:=tracex[vt];
                t2:=tracey[vt];
                vt:=tracestt[vt];
                vtx:=t1;
                vty:=t2;
        end;
        inc(d);
        kqx[d]:=vtx;
        kqy[d]:=vty;
        writeln(d-1);
        for i:=d downto 2 do
                writeln(kqx[i],' ',kqy[i],' ',kqx[i-1],' ',kqy[i-1]);
end;
function swap(u:arr;x1,y1,x2,y2:longint):arr;
var     t:longint;
begin
        swap:=u;
        t:=swap[x1,y1];swap[x1,y1]:=swap[x2,y2];swap[x2,y2]:=t;
end;
procedure mang_gt;
var     j:longint;
begin
        gt[1]:=1;
        for j:=2 to 11 do
                gt[j]:=gt[j-1]*j;
end;
function search(v:arr):longint;
var     a:array[1..30] of longint;
        t,d:longint;
begin
        for i:=1 to 3 do
                for j:=1 to n do
                        a[(i-1)*n+j]:=v[i,j];
        t:=1;
        for i:=1 to 3*n-1 do
        begin
                d:=0;
                for j:=i+1 to 3*n do
                        if a[i]>a[j] then inc(d);
                t:=t+d*gt[3*n-i];
        end;
        exit(t);
end;
procedure nhap;
begin
        readln(n);
        mang_gt;
        tx[1]:=-1;tx[2]:=0;tx[3]:=1;tx[4]:=0;
        ty[1]:=0;ty[2]:=1;ty[3]:=0;ty[4]:=-1;
        fillchar(dd,5000000,true);
        for i:=1 to 3 do
                for j:=1 to n do
                begin
                        read(a[i,j]);
                        if a[i,j]=1 then
                        begin
                                kqx:=i;
                                kqy:=j;
                        end;
                end;
end;
procedure bfs;
var
        queuearr:array[1..130000] of arr;
        queuex,queuey:array[1..130000] of longint;
        u,v:array[1..3,1..10] of longint;
        l,r,i,vt,tdx,tdy,vtu:longint;
begin
        u:=a;
        vtbd:=search(u);
        if vtbd=1 then
        begin
                writeln(0);
                exit;
        end;
        l:=1;r:=1;
        queuearr[1]:=a;
        queuex[1]:=kqx;
        queuey[1]:=kqy;
        dd[vtbd]:=false;
        repeat
                u:=queuearr[l];
                vtu:=search(u);
                tdx:=queuex[l];
                tdy:=queuey[l];
                inc(l);
                for i:=1 to 4 do
                begin
                        if not(((i=1) and (tdx=1)) or ((i=2) and (tdy=n)) or ((i=3) and (tdx=3)) or ((i=4) and (tdy=1))) then
                        begin
                                v:=swap(u,tdx,tdy,tdx+tx[i],tdy+ty[i]);
                                vt:=search(v);
                                if dd[vt] then
                                begin
                                        tracestt[vt]:=vtu;
                                        tracex[vt]:=tdx;
                                        tracey[vt]:=tdy;
                                        if vt=1 then
                                        begin
                                                result(vt,tdx+tx[i],tdy+ty[i]);
                                                exit;
                                        end;
                                        inc(r);
                                        queuearr[r]:=v;
                                        queuex[r]:=tdx+tx[i];
                                        queuey[r]:=tdy+ty[i];
                                        dd[vt]:=false;
                                end;
                        end;
                end;
        until l>r;
end;
begin
        assign(input,'bd.inp');
        assign(output,'bd.out');
        reset(input);
        rewrite(output);
        nhap;
        bfs;
        close(input);
        close(output);
end.

