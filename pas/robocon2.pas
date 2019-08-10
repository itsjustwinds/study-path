const
  fi='robocon.inp';
  fo='robocon.out';
  maxn=501;
  maxq=20*maxn*maxn;
  oo=trunc(1e9);
type
  point = record
    x,y,d : longint;
  end;
var
  dau1,cuoi1,dau2,cuoi2,i,j,n,m : longint;
  a : array[0..maxn,0..maxn] of boolean;
  q1,q2 : array[1..maxq] of point;
  d1,d2 : array[1..maxn,1..maxn] of longint;
  nowd,res : longint;
  kt : boolean;

procedure enter;
var u,v : longint;
begin
  assign(input,fi);reset(input);
  fillchar(a , sizeof(a) , false);
  readln(n,m);
  for i:=1 to n do for j:=1 to n do a[i,j] := true;
  for i:=1 to m do
    begin
      read(u,v);
      a[u,v] := false;
    end;
end;
procedure push1(x,y,z : longint);
begin
  inc(cuoi1);
  q1[cuoi1].x := x;
  q1[cuoi1].y := y;
  q1[cuoi1].d := z;
  d1[x,y] := z;
  if d2[x,y]=z then
    begin
      res := z;
      kt:=true;
      exit;
    end;
end;
procedure push2(x,y,z : longint);
begin
  inc(cuoi2);
  q2[cuoi2].x := x;
  q2[cuoi2].y := y;
  q2[cuoi2].d := z;
  d2[x,y] := z;
end;
procedure bfs2(dd : longint);
var u : point;
    i,j : longint;
begin
  while dau2<=cuoi2 do
    begin
      u := q2[dau2]; inc(dau2);
      if u.d>dd then begin dec(dau2); exit; end;
      i:=u.x;j:=u.y;
      if a[i,j-1] and (d2[i,j-1]<>dd+1) then push2(i,j-1,dd+1);
      if a[i+1,j] and (d2[i+1,j]<>dd+1) then push2(i+1,j,dd+1);
      if a[i+1,j-1] and (d2[i+1,j-1]<>dd+1) then push2(i+1,j-1,dd+1);
    end;
end;
procedure bfs1;
var u : point;
    i,j : longint;
begin
  fillchar(d1,sizeof(d1),255);
  fillchar(d2,sizeof(d2),255);
  kt := false;
  dau1 :=1; cuoi1 := 0;
  dau2 := 1; cuoi2 := 0;
  push1(1,1,0); push2(1,n,0);
  nowd := 0;
  while dau1<=cuoi1 do
    begin
      if kt then break;
      u := q1[dau1]; inc(dau1);
      if u.d=nowd then
        begin
          bfs2(nowd);
          inc(nowd);
        end;
      i := u.x ; j:=u.y;
      if a[i+1,j] and (d1[i+1,j]<>u.d+1) then push1(i+1,j,u.d+1);
      if a[i,j+1] and (d1[i,j+1]<>u.d+1) then push1(i,j+1,u.d+1);
      if a[i+1,j+1] and (d1[i+1,j+1]<>u.d+1) then push1(i+1,j+1,u.d+1);
    end;
end;
procedure process;
begin
  res := oo;
  bfs1;
end;
procedure print;
begin
  assign(output,fo);rewrite(output);
  writeln(res);
  close(output);
end;
begin
  enter;
  process;
  print;
end.
