{var
        m,n,s,p,last:longint;
        a:array[1..100,1..100] of boolean;
        dd:array[1..100] of boolean;
        stack,t:array[1..10000] of longint;
procedure nhap;
var     i,x,y:longint;
begin
        readln(n,m,s,p);
        fillchar(a,sizeof(a),false);
        for i:=1 to n do
                a[i,i]:=true;
        for i:=1 to m do
        begin
                readln(x,y);
                a[x,y]:=true;
                a[y,x]:=true;
        end;
end;
procedure xl1(i:longint);
var     j:longint;
begin
        dd[i]:=false;
        write(i,' ');
        for j:=1 to n do
                if (dd[j]) and (a[i,j]) then
                        xl1(j);
end;
procedure push(u:longint);
begin
        inc(last);
        stack[last]:=u;
end;
function pop:longint;
begin
        pop:=stack[last];
        dec(last);
end;
procedure dfs;
var u,i:longint;
begin
        fillchar(dd,sizeof(dd),true);
        last:=0;
        push(s);
        dd[s]:=false;
        while last<>0 do
        begin
        u:=pop;
        for i:=1 to n do
                if (dd[i]) and (a[u,i]) then
                begin
                        dd[i]:=false;
                        push(u);
                        push(i);
                        t[i]:=u;
                        break;
                end;
        end;
end;
procedure result;
begin
        if dd[p] then write(-1)
        else while p<>s do
        begin
                write(p,'<');
                p:=t[p];
        end;
        write(p);
end;
begin
        assign(input,'graph.inp');
        assign(output,'graph.out');
        reset(input);
        rewrite(output);
        nhap;
        fillchar(dd,sizeof(dd),true);
        xl1(s);
        writeln;
        dfs;
        result;
        close(input);close(output);
end.    }
var
        a:array[1..100,1..100] of boolean;
        q,t:array[1..10000] of longint;
        dd:array[1..100] of boolean;
        i,x,y,n,m,s,p,l,r:longint;
procedure nhap;
begin
        readln(n,m,s,p);
        for i:=1 to n do
                a[i,i]:=true;
        for i:=1 to m do
        begin
                readln(x,y);
                a[x,y]:=true;
                a[y,x]:=true;
        end;
end;
procedure xuly1;
var     i,j,k,dem:longint;
begin
        fillchar(dd,sizeof(dd),true);
        dem:=0;
        for i:=1 to n do
                for j:=1 to n do
                        for k:=1 to n do
                                a[j,k]:=a[j,k] or a[i,j] and a[i,k];
        for k:=1 to n do
        if dd[k] then
        begin
        dd[k]:=false;
        inc(dem);
        writeln(dem,':');
        write(k,' ');
        for i:=1 to n do
                if (dd[i]) and (a[k,i]) then
                begin
                        dd[i]:=false;
                        write(i,' ');
                end;
        writeln;
        end;
end;
{procedure push(u:longint);
begin
        dd[u]:=false;
        inc(r);
        q[r]:=u;
end;
function pop:longint;
begin
        pop:=q[l];
        inc(l);
end;
procedure bfs;
var     u,i,j:longint;
begin
        fillchar(dd,sizeof(dd),true);
        r:=0;l:=1;
        push(s);
        while l<=r do
        begin
                u:=pop;
                for i:=1 to n do
                        if (dd[i]) and (a[u,i]) then
                        begin
                                push(i);
                                t[i]:=u;
                        end;
        end;
end;
procedure result;
begin
        if dd[p] then write(-1)
        else while s<>p do
        begin
                write(p,'<');
                p:=t[p];
        end;
        write(p);
end;}
begin
        assign(input,'graph.inp');
        assign(output,'graph.out');
        reset(input);
        rewrite(output);
        nhap;
       { bfs;
        result;  }
        xuly1;
        close(input);
        close(output);
end.