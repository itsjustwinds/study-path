uses math;
const inp='MTerCHEF.inp';
        out='MTERCHEF.out';
type edges=record pos,max:longint; end;
var   k,n,m:longint;
      st:array[1..4*1000] of edges;
      a,s,pos,f,trace:array[0..1010] of longint;
      res:array[1..2*1010] of longint;

procedure enter;
var  i:longint;
begin
    assign(input,inp);
    assign(output,out);
    reset(input);
    rewrite(output);
    readln(n,m);
    for i:=1 to n do
    begin
        read(a[i]);
        s[i]:=s[i-1]+a[i];
        pos[i]:=i;
    end;
end;

procedure built(id,l,r:longint);
var  mid:longint;
begin
    if l=r then
    begin
        st[id].max:=a[l];
        st[id].pos:=pos[l];
        exit;
    end;
    mid:=(l+r) shr 1;
    built(id*2,l,mid);
    built(id*2+1,mid+1,r);
    st[id].max:=max(st[id*2].max,st[id*2+1].max);
    if st[id].max=st[id*2].max then st[id].pos:=st[id*2].pos
    else st[id].pos:=st[id*2+1].pos;
end;

function get(id,l,r,i,j:longint):longint;
var mid:longint;
begin
    if (j<l) or(i>r) then exit(-maxlongint);
    if (i<=l) and (r<=j) then
    begin
        exit(st[id].max);
    end;
    mid:=(l+r) shr 1;
    exit(max(get(id*2,l,mid,i,j),get(id*2+1,mid+1,r,i,j)));
end;

procedure process;
var  i,j:longint;
begin
    built(1,1,n);

    for i:=1 to n do
    begin
        f[i]:=maxlongint;
        trace[i]:=i;
        for j:=i downto 1 do
        begin
            if s[i]-s[j-1] <=m then
            begin
               if  f[i]>f[j-1]+get(1,1,n,j,i) then
                begin
                   f[i]:=get(1,1,n,j,i)+f[j-1];
                   trace[i]:=trace[j];
                end;
            end;
        end;
    end;
    writeln(f[n]);
    while i<>0 do
    begin
        for j:=i downto trace[i] do
        begin
            inc(k);
            res[k]:=j;
        end;
        inc(k);
        res[k]:=0;
        i:=trace[i]-1;
    end;
    for i:=k-1 downto 1 do
        if res[i]<>0 then write(res[i],' ')
        else writeln;
end;

begin
    enter;
    process;
end.
