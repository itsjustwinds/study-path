const inp='LMAZE.inp';
        out='LMAZE.out';
var   n,res1,res2:longint;
      ok:boolean;
      head:array[0..4*100000] of longint;
      adj:array[0..4*100000] of longint;
      s,q,trace:array[1..100000] of longint;
      fr:array[1..100000] of boolean;
procedure enter;
var  i:longint;
begin
    assign(input,inp);
    assign(output,out);
    reset(input);
    rewrite(output);
    readln(n);
    ok:=true;
    for i:=1 to n do
    begin
        read(s[i]);
        if s[i]=i then ok:=false;
        inc(head[s[i]]);
    end;
    for i:=1 to n do head[i]:=head[i-1]+head[i];
    head[n+1]:=n;
    for i:=1 to n do
    begin
        adj[head[s[i]]]:=i;
        dec(head[s[i]]);
    end;
end;

procedure process;
var  l,r,u,v,i:longint;
begin
    fillchar(fr,n,true);
    l:=1;
    r:=1;
    q[1]:=1;
    fr[1]:=false;
    while l<=r do
    begin
        u:=q[l];
        inc(l);
        if u=n then break;
        for v:=head[u]+1 to head[u+1] do
            if fr[adj[v]]=true then
            begin
                inc(r);
                q[r]:=adj[v];
                fr[adj[v]]:=false;
                trace[adj[v]]:=u;
            end;
    end;
    if fr[n]=false then
    begin
    i:=n;
    res1:=0;
    while i<>0 do
    begin
        inc(res1);
        i:=trace[i];
    end;
    res1:=res1-1;
    end
    else ok:=false;
    ///////////////////////////
    l:=1;
    r:=1;
    fillchar(q,sizeof(q),0);
    fillchar(fr,n,true);
    fillchar(trace,n,0);
    q[1]:=n;
    fr[n]:=false;
    while l<=r do
    begin
        u:=q[l];
        inc(l);
        if u=1 then break;
        for v:=head[u]+1 to head[u+1] do
            if fr[adj[v]] then
            begin
                inc(r);
                q[r]:=adj[v];
                fr[adj[v]]:=false;
                trace[adj[v]]:=u;
            end;
    end;
    if fr[1]=false then
    begin
    i:=1;
    res2:=0;
    while i<>n do
    begin
        inc(res2);
        i:=trace[i];
    end;
    res2:=res2;
    end
    else ok:=false;
    if ok=true then
    writeln(res1+(res2+res1-2)*2)
    else writeln(-1);
end;

begin
    enter;
    process;
end.
