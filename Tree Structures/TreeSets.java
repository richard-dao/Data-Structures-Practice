Set<Integer> treeSet = new TreeSet<Integer>();
		treeSet.add(9);
		treeSet.add(10);
		treeSet.add(0);
		treeSet.add(1);
		treeSet.add(2);
		treeSet.remove(10);
		treeSet.add(-1);
		treeSet.add(10);
		
		Iterator<Integer> itr2 = treeSet.iterator();
		while (itr2.hasNext()) {
			int next = itr2.next();
			System.out.print(next + ", ");
			itr2.remove();
		}
		
		for (int i : treeSet) {
			System.out.print(i + ", ");
		}
		
		System.out.println(treeSet.toString());
