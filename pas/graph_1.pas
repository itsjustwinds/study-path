const
        fi='graph.inp';
        fo='graph.out';
var
        a:array[1..1000,1..1000] of boolean;
        dd:array[1..100000] of boolean;
        t,q:array[1..100000] of longint;
        n,m,x,y,last,first,i,j:longint;
        f:text;
procedure nhap;
var     k,i,j:longint;
begin
        assign(f,fi);
        reset(f);
        readln(f,n,m,x,y);
        fillchar(a,sizeof(a),false);
        for k:=1 to m do
        begin
                readln(f,i,j);
                a[i,j]:=true;
                a[j,i]:=true;
        end;
        close(f);
end;
procedure push(u:longint);
begin
        inc(last);
        q[last]:=u;
        dd[u]:=false;
end;
function pop:longint;
begin
        pop:=q[first];
        inc(first);
end;
procedure bfs;
var
        u,i:longint;
begin
        repeat
                u:=pop;
                for i:=1 to n do
                    if (a[u,i]) and (dd[i]) then
                    begin
                        push(i);
                        t[i]:=u;
                    end;
        until first>last;
end;
procedure result;
begin
        if (dd[y]) then write(f,-1)
        else
        while x<>y do
        begin
                write(f,y,' ');
                y:=t[y];
        end;
        writeln(f,y);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        fillchar(dd,sizeof(dd),true);
        last:=1;
        first:=1;
        dd[x]:=false;
        q[last]:=x;
        bfs;
        result;
        close(f);
end;
begin
        nhap;
        xuat;
end.
