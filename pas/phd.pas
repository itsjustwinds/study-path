uses math;
type  pRE=^ tRE;
        tre= RECORD
                V,l : longint;
                next: pRE;
                end;
var n,m,nn: longint;
        oo: int64 = high(int64) div 2;
        p: array[0..1000000] of int64;
        ds: array[0..1000000] of pRE;
        d,heap,pos,X: array[0..1000000] of int64;
procedure init(u,v,l: longint);
var tg: pRE;
begin
        new(tG);
        tg^. v:= v;
        tg^. l:= l;
        tg^. next:= ds[u];
        ds[u]:=tg;
end;
procedure doc;
var i,j,u,v,l: longint;
begin
        read(n);
        for i:=1 to n do read(p[i]);
        read(m);
        for i:=1 to m do
        begin
                read(u,v,l);
                init(u,v,l);
                init(v,u,l);
        end;

end;
procedure upheap(i:longint);
var p,c,tg:longint;
begin
        c:=i;
        p:= i div 2;
        while ( p <> 0 ) and ( d[heap[p]] > d[heap[c]]) do
        begin
                pos[heap[c]]:= p;
                pos[heap[p]]:= c;
                tg:= heap[c];
                heap[c]:= heap[p];
                heap[p]:= tg;
                c:= p;
                p:= c div 2;
        end;
end;
procedure downheap;
var p,c,tg:longint;
begin
           p:= 1;
           c:=2;
           while ( c <= nn ) do
           begin
                if (c< nn ) and ( d[heap[c]] > d[heap[c+1]] ) then inc(c);
                if d[heap[p]] <= d[heap[c]] then break;
                 pos[heap[c]]:= p;
                 pos[heap[p]]:= c;
                 tg:= heap[c];
                 heap[c]:= heap[p];
                 heap[p]:= tg;
                 p:=c;
                 c:= p*2;
           end;
end;
procedure push(u:longint);
begin
        if pos[u] = 0 then
        begin
                inc(nn);
                heap[nn]:= u;
                pos[u]:= nn;
        end;
        upheap(pos[u]);
end;
procedure pop;
begin
        pos[heap[1]]:= 0 ;
        heap[1]:= heap[nn];
        heap[nn]:=0;
        pos[heap[1]]:= 1;
        dec(nn);
        if nn > 0 then
        downheap;
end;
procedure dijktra;
var i,j,u,v,l : longint; tg: pRE;
begin
        for i:=1 to n do
        begin
                d[i]:= oo;
                pos[i]:=0;
        end;
        d[1]:= 0;
        X[1]:= P[1];
        nn:=0;
        push(1);
        repeat
                u:= heap[1];
                pop;
                if ( d[u] = oo ) then break;
                if u = N then
                begin
                        write(D[u],' ', x[u]);
                        exit;
                end;
                tg:= ds[u];
                while tg <> nil do
                begin
                        v:=tg^. v;
                        l:= tg^. l;
                        tg:= tg^. next;
                        if d[v] >= d[u] + l then
                        begin
                                if d[v] > d[u]+ l then
                                begin
                                        d[v]:= D[u] + l;
                                        X[v]:= X[u] + p[v];
                                        push(v);
                                end else x[v]:= max(x[v], x[u] + p[v]);
                        end;
                end;
        until nn = 0 ;
        write('impossible');
end;
begin
        assign(input,'phd.inp');
        assign(output,'phd.out');
        reset(input);
        rewrite(output);
        doc;
        dijktra;
        close(input);
        close(output);
end.
